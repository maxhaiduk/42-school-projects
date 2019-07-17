import React from 'react';

import './submit-button.css';

const SubmitButton = (props) => {

    return (
        <input
            className='submit-button'
            type='submit'
            value={ props.value || 'Submit' }
        />
    )
};

export default SubmitButton;