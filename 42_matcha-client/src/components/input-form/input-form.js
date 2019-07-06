import React, { Component } from 'react';
import InputField from './components/input-field';

class InputForm extends Component {

    constructor(props) {
        super(props);

        this.children = this._prepareChildComponents(this.props.children);
        this.state = this._prepareInitialState(this.children);

        console.log(this.state);
    }

    handleOnInput(inputName, value) {

        const state = {};

        state[inputName] = {
            'value': value
        };

        this.setState(state);
    }

    _prepareChildComponents(children) {
        return React.Children.map(children, child => {
            const childName = child.props.name;

            child = React.cloneElement(child, {
                id: this.props.id + '-' +  childName,
                onInput: (name, value) => { this.handleOnInput(name, value) }
            });

            return child;
        });
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
                    this.children
                }
            </form>
        )
    }
}

export default InputForm;
