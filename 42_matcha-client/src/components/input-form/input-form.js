import React, { Component } from 'react';
import InputField from './components/input-field';
import InputValidator from './components/input-validator';
import UniqueValidator from './components/input-validator/validators/unique-validator';

import './input-form.css';

class InputForm extends Component {


    state = this.prepareInitialState(this.props.children);

    /**
     * @param {Component[] | Component} children
     * @return {object} state
     */
    prepareInitialState(children) {

        let state = { 'inputFields' : {} };

        React.Children.map(children, child => {
            if (child.type !== InputField ||
                child.props.name === undefined) {
                return;
            }

            const { rules, unique } = child.props;

            if (unique && !unique.timeout) {
                unique.timeout = 1500;
            }

            state['inputFields'][child.props.name] = {
                value: null,
                valid: null,
                rules,
                shouldValidate: Boolean(rules),
                unique,
                ...(unique && { timerId : null }),
                ...(unique && { loading : false })
            };
        });

        return state;
    }

    /**
     * @param {string} inputName
     * @param {string} value
     */
    handleOnInput(inputName, value) {
        const { shouldValidate, unique } = this.state.inputFields[inputName];

        this.updateFieldState(inputName, { value });

        if (!shouldValidate) {
            return;
        }
        const { valid, errorMessage } = this.validateField(inputName, value);
        this.updateFieldState(inputName, { valid, errorMessage });

        if (valid && unique) {
            this.checkUnique(inputName, value);
        }

    }

    /**
     * Updates state of specified input field
     *
     * @param {string} inputName
     * @param {object} newState
     */
    updateFieldState(inputName, newState){
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
                    errorMessage
                } = this.validateField(inputName, inputState.value);
                this.updateFieldState(inputName, { valid, errorMessage });
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

        let { timerId, unique } = this.state.inputFields[inputName];
        if (timerId) {
            clearTimeout(timerId);
        }

        timerId = setTimeout(async () => {
            await uniqueValidator.validate(value, unique.handler)
                .then(({ valid, errorMessage }) => {
                    console.log(errorMessage);
                    this.updateFieldState(inputName, { valid, errorMessage });
                } )
        }, unique.timeout);

        this.updateFieldState(inputName, { timerId });
    }


    /**
     * Supplements child elements with needed props
     *
     * @return {Component[] | Component}
     */
    getChildren() {
        return React.Children.map(this.props.children, child => {

            if (child.type !== InputField ||
                child.props.name === undefined) {
                return child;
            }

            const childName = child.props.name;
            const fieldState = (this.state['inputFields'] || {})[childName] || {};
            const { value, shouldValidate, valid, unique, errorMessage } = fieldState;

            child = React.cloneElement(child, {
                key: childName,
                id: this.props.id + '-' +  childName,
                value,
                onInput: (name, value) => { this.handleOnInput(name, value) },
                ...(shouldValidate && { valid }),
                ...((shouldValidate || unique) && { errorMessage })
            });

            return child;
        })
    }

    handleOnSubmit(event) {
        event.preventDefault();
        this.validateForm();
        this.props.onSubmit(this.state)
    };

    render () {
        const { id } = this.props;

        return (
            <div className='form-container'>
                <form
                    id={ id }
                    className='input-form'
                    onSubmit={ (event) => { this.handleOnSubmit(event) }}>
                {
                    this.getChildren()
                }
                </form>
            </div>
        )
    }
}

export default InputForm;
