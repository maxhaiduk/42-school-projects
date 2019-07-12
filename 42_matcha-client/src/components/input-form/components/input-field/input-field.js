import React from 'react';
import cx from 'react-classset';

import './input-field.css';

function InputField(props) {

    const { type, id, name, label, valid } = props;
    const required = (props.rules || []).includes('required');

    let classes = cx({
        'input-field': true,
        'valid-input': valid === true,
        'invalid-input': valid === false,
    });

    return (
        <div id={ id } className='input-field-container'>
            <label className='input-field-label'>
                { required ? label + '*' : label }
            </label>
            <input
                className={ classes }
                type={ type }
                name={ name }
                onInput={ (event) => {
                    props.onInput(props.name, event.target.value)
                }}
            />
        </div>
    )
}

export default InputField;
