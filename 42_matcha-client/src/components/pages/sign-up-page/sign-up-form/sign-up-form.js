import React from 'react';
import InputForm, { InputField, SubmitButton } from '~/components/input-form';
import ApiService from '~/services/api-service';

const SignUpForm = () => {

    const apiService = new ApiService();

    const handleSubmit = (formState) => {
        console.log('Sign up form is submitted with values');
        console.log(formState);
    };

    return (
        <InputForm id='login-form' onSubmit={ handleSubmit }>
            <InputField type='text' name='login' label='Login'
                unique={{
                    handler: apiService.checkAvailability,
                    timeout: 1000,
                }}
                rules={[
                    'required',
                    {
                        length: {
                            max: 12,
                            min: 4,
                        }
                    },
                ]}/>
            <InputField type='password' name='password' label='Password' rules={[
                'required',
                'password'
            ]}/>
            <InputField type='password' name='confirm-password'
                        label='Confirm password' rules={[
                'required',
                {
                    equal: 'password'
                }
            ]}/>
            <SubmitButton value='sign up'/>
        </InputForm>
    );
};

export default SignUpForm;