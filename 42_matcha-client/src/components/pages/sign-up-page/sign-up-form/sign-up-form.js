import React from 'react';
import InputForm, { InputField, SubmitButton } from '~/components/input-form';

const SignUpForm = () => {

    const handleSubmit = (formState) => {
        console.log('Sign up form is submitted with values');
        console.log(formState);
    };

    return (
        <InputForm id='login-form' onSubmit={ handleSubmit }>
            <InputField type='text' name='login' label='Login' rules={[
                'required',
                {
                    length: {
                        max: 12,
                        min: 4,
                    }
                },
            ]}/>
            <InputField type='password' name='password' label='Password'/>
            <InputField type='password' name='confirm-password'
                        label='Confirm password' rules={[
                {
                    equal: 'password'
                }
            ]}/>
            <SubmitButton value='sign up'/>
        </InputForm>
    );
};

export default SignUpForm;