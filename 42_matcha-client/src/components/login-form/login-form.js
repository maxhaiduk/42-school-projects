import React from 'react';
import InputForm, { InputField } from '../input-form';

const LoginForm = () => {

    return (
        <InputForm id='login-form'>
            <InputField type='text' name='login' label='Login' rules={[
                {
                    length: {
                        max: 12,
                        min: 4,
                    }
                },
                'required',
            ]}/>
            <InputField type='password' name='password' label='Password'/>
            <InputField type='password' name='confirm-password' label='Confirm password' rules={[
                {
                    equal: 'password'
                }
            ]}/>
            <InputField type='submit' value='submit' />
        </InputForm>
    );
};

export default LoginForm;
