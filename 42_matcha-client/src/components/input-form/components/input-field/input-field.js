import React, { Component } from 'react';

export default class InputField extends Component {

    constructor(props) {
        super(props);
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
                        onInput={ () => { console.log(event) } }
                    />
                </label>
            </div>
        )
    }
};

