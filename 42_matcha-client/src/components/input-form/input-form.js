import React, { Component } from 'react';
import InputField from './components/input-field';
import InputValidator from './components/input-validator';

class InputForm extends Component {

    constructor(props) {
        super(props);

        this.state = this._prepareInitialState(this.props.children);
        this.inputValidator = new InputValidator();
    }

    /**
     * @param {Comment[] | Component} children
     * @private
     *
     * @return {object} state
     */
    _prepareInitialState(children) {

        let state = { 'inputFields' : {} };

        React.Children.map(children, child => {
            if (child.type !== InputField ||
                child.props.name === undefined) {
                return;
            }

            state['inputFields'][child.props.name] = {
                value: null,
                isValid: false,
                rules: child.props.rules,
            };
        });

        return state;
    }

    /**
     * @param {string} inputName
     * @param {string} value
     */
    handleOnInput(inputName, value) {

        const rules = this.state.inputFields[inputName].rules;

        const isValid = this.inputValidator.validate(value, rules);

        console.log('isValid', isValid);

        this.setState((state) => {
            return {
                inputFields: {
                    ...state.inputFields,
                    [inputName]: {
                        ...state.inputFields[inputName],
                        'value': value
                    }
                },
            }
        })
    }

    render () {
        return (
            <form>
            {
                React.Children.map(this.props.children, child => {
                    const childName = child.props.name;
                    const value = ((this.state['inputFields'] || {})[childName] || {}).value;

                    child = React.cloneElement(child, {
                        key: childName,
                        id: this.props.id + '-' +  childName,
                        value: value,
                        onInput: (name, value) => { this.handleOnInput(name, value) }
                    });

                    return child;
                })
            }
            </form>
        )
    }
}

export default InputForm;
