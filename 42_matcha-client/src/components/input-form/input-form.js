import React, { Component } from 'react';
import InputField from './components/input-field';
import InputValidator from './components/input-validator';

class InputForm extends Component {

    constructor(props) {
        super(props);

        this.state = this.prepareInitialState(this.props.children);
        this.inputValidator = new InputValidator();
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

        const {rules, shouldValidate} = this.state.inputFields[inputName];

        const valid = shouldValidate ?
                    this.inputValidator.validate(value, rules, this.state.inputFields) :
                    null;

        this.setState((state) => {
            return {
                inputFields: {
                    ...state.inputFields,
                    [inputName]: {
                        ...state.inputFields[inputName],
                        value,
                        ...(shouldValidate && {valid})
                    }
                },
            }
        })
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
            const { value, shouldValidate, valid } = fieldState;

            child = React.cloneElement(child, {
                key: childName,
                id: this.props.id + '-' +  childName,
                value,
                ...(shouldValidate && { valid }),
                onInput: (name, value) => { this.handleOnInput(name, value) }
            });

            return child;
        })
    }

    render () {
        return (
            <form role="form" className="form-horizontal">
            {
                this.getChildren()
            }
            </form>
        )
    }
}

export default InputForm;
