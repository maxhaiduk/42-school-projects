import React from 'react';
import cx from 'react-classset';

import './input-field.css';

const InputField = (props) => {

    const { type, id, name, label, valid } = props;

    let classes = cx({
        'form-control': true,
        'invalid-input': valid === false
    });

    return (
        <div id={ id }>
            <label>
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
};

export default InputField;

