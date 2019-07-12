import React, { Component } from 'react';
import InputField from './components/input-field';
import InputValidator from './components/input-validator';

import './input-form.css';

class InputForm extends Component {

    constructor(props) {
        super(props);

        this.state = this.prepareInitialState(this.props.children);
    }

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

            state['inputFields'][child.props.name] = {
                value: null,
                valid: null,
                rules: child.props.rules,
                shouldValidate: Boolean(child.props.rules)
            };
        });

        return state;
    }

    /**
     * @param {string} inputName
     * @param {string} value
     */
    handleOnInput(inputName, value) {
        const {shouldValidate} = this.state.inputFields[inputName];

        const {
            valid,
            errorMessage
        } = shouldValidate ? this.validate(inputName, value): {};

        console.log({
            valid, errorMessage
        });

        this.setState((state) => {
            return {
                inputFields: {
                    ...state.inputFields,
                    [inputName]: {
                        ...state.inputFields[inputName],
                        value,
                        ...(shouldValidate && {valid}),
                        ...(shouldValidate && !valid && {errorMessage})
                    }
                },
            }
        })
    }

    /**
     * @param {string} inputName
     * @param {string} value
     * @returns {boolean | null}
     */
    validate(inputName, value) {
        let validator = new InputValidator(inputName, this.state.inputFields);
        const {rules} = this.state.inputFields[inputName];

        let result = validator.validate(value, rules);

        return result;
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
            const { value, shouldValidate, valid, errorMessage } = fieldState;

            child = React.cloneElement(child, {
                key: childName,
                id: this.props.id + '-' +  childName,
                value,
                onInput: (name, value) => { this.handleOnInput(name, value) },
                ...(shouldValidate && { valid }),
                ...(shouldValidate && !valid && {errorMessage})
            });

            return child;
        })
    }

    render () {
        const { id } = this.props;

        return (
            <div className='form-container'>
                <form id={ id } className='input-form' >
                {
                    this.getChildren()
                }
                </form>
            </div>
        )
    }
}

export default InputForm;
