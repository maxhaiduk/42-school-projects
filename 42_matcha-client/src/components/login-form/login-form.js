import React from 'react';
import InputForm, { InputField } from '../input-form';

const LoginForm = () => {

    return (
        <InputForm id='login-form'>
            <InputField type='text' name='login' label='Login'/>
            <InputField type='password' name='password' label='Password'/>
            <InputField type='submit' value='submit' />
        </InputForm>
    );
};

export default LoginForm;

