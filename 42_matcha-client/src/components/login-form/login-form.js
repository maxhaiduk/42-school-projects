import React from 'react';
import InputForm, { InputField } from '../input-form';

const LoginForm = () => {

    return (
        <InputForm id='login-form'>
            <InputField type='text' name='login' label='Login' checks={[
                'emptiness',
                'word',
                'length'
            ]}/>
            <InputField type='password' name='password' label='Password'/>
            <InputField type='submit' value='submit' />

            <a href="">Some link</a>
        </InputForm>
    );
};

export default LoginForm;

