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
            <InputField type='text' name='login'
                unique={{
                    handler: apiService.checkAvailability,
                    timeout: 2000,
                }}
                rules={[
                    'required',
                    {
                        length: {
                            max: 12,
                            min: 4,
                        }
                    },
                ]}
            />
            <InputField type='email' name='email' rules={[
                'email',
            ]}/>
            <InputField type='text' name='first-name' rules={[
                    { length: { max: 12 } },
            ]}/>
            <InputField type='text' name='second-name' rules={[
                    { length: { max: 12 } },
            ]}/>
            <InputField type='password' name='password' rules={[
                'required',
                'password'
            ]}/>
            <InputField type='password' name='confirm-password' rules={[
                'required',
                {
                    equal: 'password'
                }
            ]}/>
            <SubmitButton/>
        </InputForm>
    );
};

export default SignUpForm;