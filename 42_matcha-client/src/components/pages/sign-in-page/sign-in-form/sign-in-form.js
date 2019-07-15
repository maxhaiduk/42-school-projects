import React from 'react';
import InputForm, { InputField } from '../../../input-form';

const SignInForm = () => {

    return (
        <InputForm id='sign-in-form'>
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
            <InputField type='submit' value='submit' />
        </InputForm>
    );
};

export default SignInForm;
