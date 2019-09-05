import React, { Component } from 'react';
import InputField from './components/input-field';
import InputValidator from './components/input-validator';
import UniqueValidator
  from './components/input-validator/validators/unique-validator';
import classNames from 'classnames';


class InputForm extends Component {


  state = this.prepareInitialState(this.props.children);

  /**
   * @param {Component[] | Component} children
   * @return {object} state
   */
  prepareInitialState(children) {

    let state = {'inputFields': {}};

    React.Children.map(children, child => {
      if (child.type !== InputField) {
        return;
      }

      const {rules, unique} = child.props;

      if (unique && !unique.timeout) {
        unique.timeout = 1500;
      }

      state['inputFields'][child.props.name] = {
        value: null,
        valid: null,
        rules,
        shouldValidate: Boolean(rules),
        unique,
        ...(unique && {timerId: null}),
        ...(unique && {loading: false})
      };
    });

    return state;
  }

  /**
   * @param {string} inputName
   * @param {string} value
   */
  handleOnInput(inputName, value) {
    const {shouldValidate, unique, timerId} = this.state.inputFields[inputName];

    this.updateFieldState(inputName, {value});

    if (!shouldValidate) {
      return;
    }
    const {valid, message} = this.validateField(inputName, value);
    this.updateFieldState(inputName, {valid, message});

    if (valid && unique) {
      this.checkUnique(inputName, value);
    } else if (!valid && unique && timerId) {
      this.clearTimer(inputName, timerId);
    }
  }

  /**
   * Updates state of specified input field
   *
   * @param {string} inputName
   * @param {object} newState
   */
  updateFieldState(inputName, newState) {
    this.setState((state) => {
      return {
        inputFields: {
          ...state.inputFields,
          [inputName]: {
            ...state.inputFields[inputName],
            ...newState,
          }
        },
      }
    })
  }

  validateForm() {
    Object.entries(this.state.inputFields)
      .filter(([, inputState]) => inputState.shouldValidate)
      .map(([inputName, inputState]) => {
        const {
          valid,
          message
        } = this.validateField(inputName, inputState.value);
        this.updateFieldState(inputName, {valid, message});
      });
  }

  /**
   * @param {string} inputName
   * @param {string} value
   * @returns {object}
   */
  validateField(inputName, value) {
    let validator = new InputValidator(inputName, this.state.inputFields);
    const {rules} = this.state.inputFields[inputName];

    return validator.validate(value, rules);
  }

  /**
   * @param {string} inputName
   * @param {string} value
   */
  checkUnique(inputName, value) {
    const uniqueValidator = new UniqueValidator(inputName);

    let {timerId, unique} = this.state.inputFields[inputName];

    if (timerId) {
      this.clearTimer(inputName, timerId);
    }

    timerId = setTimeout(async () => {
      this.updateFieldState(inputName, {loading: true});

      await uniqueValidator.validate(value, unique.handler)
        .then(({valid, message}) => {
          this.updateFieldState(inputName, {valid, message, loading: false});
        })
    }, unique.timeout);

    this.updateFieldState(inputName, {timerId});
  }

  /**
   * @param {string} inputName
   * @param {number} timerId
   */
  clearTimer(inputName, timerId) {
    clearTimeout(timerId);
    this.updateFieldState(inputName, {timerId: null});
  }

  /**
   * Supplements child elements with needed props
   *
   * @return {Component[] | Component}
   */
  getChildren() {
    return React.Children.map(this.props.children, child => {

      if (child.type !== InputField) {
        return child;
      }

      const childName = child.props.name;
      const fieldState = (this.state['inputFields'] || {})[childName] || {};
      const {value, shouldValidate, valid, unique, loading, message} = fieldState;

      child = React.cloneElement(child, {
        key: childName,
        id: this.props.id + '-' + childName,
        value,
        onInput: (name, value) => {
          this.handleOnInput(name, value)
        },
        ...(shouldValidate && {valid}),
        ...((shouldValidate || unique) && {message}),
        ...(unique && {loading})
      });

      return child;
    })
  }

  handleOnSubmit(event) {
    event.preventDefault();
    this.validateForm();
    this.props.onSubmit(this.state)
  };

  render() {
    const {id} = this.props;

    return (
      <form
        id={id}
        className={classNames('input-form', this.props.className)}
        onSubmit={(event) => {
          this.handleOnSubmit(event)
        }}>
        {
          this.getChildren()
        }
      </form>
    )
  }
}

export default InputForm;
