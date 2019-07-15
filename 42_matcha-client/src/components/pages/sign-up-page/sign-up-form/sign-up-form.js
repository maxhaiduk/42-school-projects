import React from 'react';
import InputForm, { InputField, SubmitButton } from '~/components/input-form';

const SignUpForm = () => {

    return (
        <InputForm id='login-form'>
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
            <InputField type='password' name='confirm-password' label='Confirm password' rules={[
                {
                    equal: 'password'
                }
            ]}/>
            <SubmitButton value='sign up'/>
        </InputForm>
    );
};

export default SignUpForm;