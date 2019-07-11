import React from 'react';
import cx from 'react-classset';

import './input-field.css';

function InputField(props) {

    console.log(props);
    const { type, id, name, label, valid } = props;

    let classes = cx({
        'input-field': true,
        'invalid-input': valid === false,
        'focus:outline-none': true,
        'focus:shadow-outline': true
    });

    return (
        <div id={ id } className='input-field-container'>
            <label className='input-field-label'>
                { label }

            </label>
            <input
                className={ classes }
                type={ type }
                name={ name }
                onInput={ (event) => { props.onInput(props.name, event.target.value) }}
            />
        </div>
    )
}

export default InputField;
