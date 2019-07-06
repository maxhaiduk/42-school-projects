import React, { Component } from 'react';
import InputField from './components/input-field';
import InputChecker from './components/input-checker';

class InputForm extends Component {

    constructor(props) {
        super(props);

        this.state = this._prepareInitialState(this.props.children);
        this.inputChecker = new InputChecker();
    }

    handleOnInput(inputName, value) {

        const state = {};

        state[inputName] = {
            'value': value
        };

        state['last_changed'] = inputName;

        this.setState(state);
    }

    _prepareInitialState(children) {

        let state = {};

        React.Children.map(children, child => {
            if (child.type !== InputField ||
                child.props.name === undefined) {
                return;
            }

            state[child.props.name] = {
                value: null,
                isValid: false,
            };
        });

        return state;
    }


    render () {
        return (
            <form>
                {
                    React.Children.map(this.props.children, child => {

                        const childName = child.props.name;
                        const value = (this.state[childName] || {}).value;

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
