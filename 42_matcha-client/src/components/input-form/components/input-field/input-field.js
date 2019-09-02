import React from 'react';
import cx from 'react-classset';
import { StringHelper } from '~/helpers';
import Spinner from '~/components/spinner';

import './input-field.css';

const InputField = (props) => {

    const { type, id, name, valid, message, loading } = props;
    let { label=StringHelper.toHumanCaseCap(name) } = props;
    const required = (props.rules || []).includes('required');

    const inputId = id + '-input';

    let classes = cx({
        'input-field': true,
        'valid-input': valid === true,
        'invalid-input': valid === false,
    });

    return (
        <div id={ id } className='input-field-container'>
            <label className='input-field-label' htmlFor={ inputId }>
                { required ? label + '*' : label }
            </label>
            { message ?
                <p className={valid ? 'successMessage' : 'errorMessage'}>{message}</p> :
                null
            }
            <div className='input-container'>
                <input
                    id = { inputId }
                    className={ classes }
                    type={ type }
                    name={ name }
                    disabled={ loading }
                    onChange={ (event) => {
                        props.onInput(props.name, event.target.value)
                    }}
                />
                { loading ? <Spinner width={25} thickness={15}/> : null }
            </div>
        </div>
    )
};

export default InputField;
