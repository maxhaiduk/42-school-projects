import React from 'react';

const InputField = (props) => {

        const { type, id, name, label } = props;

        return (
            <div>
                <label>
                    { label }
                    <input
                        className={ props.className }
                        type={ type }
                        id={ id }
                        name={ name }
                        onInput={ () => { props.onInput(props.name, event.target.value) }}
                    />
                </label>
            </div>
        )
};

export default InputField;

