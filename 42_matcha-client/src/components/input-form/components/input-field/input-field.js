import React, { Component } from 'react';
import InputChecker from '../input-checker';

export default class InputField extends Component {

    constructor(props) {
        super(props);

        this.checker = new InputChecker();
        this.state = {
            wasChanged: false,
            isValid: false,
        }
    }

    render() {
        const { type, id, name, label } = this.props;

        return (
            <div>
                <label> { label }
                    <input 
                        type={ type }
                        id={ id }
                        name={ name }
                        onInput={ () => {
                            // console.log(event);
                            let value = event.target.value;
                            // console.log('event from FIELD');
                            this.checker.sayHello();
                            this.props.onInput(this.props.name, value);
                        }}
                    />
                </label>
            </div>
        )
    }
};

