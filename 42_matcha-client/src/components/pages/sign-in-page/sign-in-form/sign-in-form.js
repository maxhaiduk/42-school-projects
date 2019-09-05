import React from 'react';
import InputForm, { InputField } from '~/components/input-form';

const SignInForm = () => {

    return (
        <InputForm id='sign-in-form'>
            <InputField type='text' name='login' label='Login'/>
            <InputField type='password' name='password' label='Password'/>
        </InputForm>
    );
};

export default SignInForm;
