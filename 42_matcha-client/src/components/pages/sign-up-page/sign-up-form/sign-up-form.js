import React from 'react';
import InputForm, { InputField, SubmitButton } from '~/components/input-form';
import { Button, makeStyles } from "@material-ui/core";
import { ValidatorForm } from "react-material-ui-form-validator";

const useStyles = makeStyles(() => ({
  container: {
    display: 'flex',
    flexDirection: 'column',
    alignItems: 'center',
  },
  textField: {
    marginTop: 20,
    width: '100%',
  },

  button: {
    marginTop: 20,
  }
}));

const SignUpForm = () => {

  const classes = useStyles();

  const handleSubmit = (formState) => {
    console.log('Sign up form is submitted with values');
    console.log(formState);
  };

  return (
    <InputForm className={classes.container} id='sign-up-form'
               onSubmit={handleSubmit}>
      <InputField className={classes.textField} type='text' name='username'
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
      {/*<InputField type='email' name='email' rules={[*/}
      {/*    'email',*/}
      {/*]}/>*/}
      {/*<InputField type='text' name='first-name' rules={[*/}
      {/*        { length: { max: 12 } },*/}
      {/*]}/>*/}
      {/*<InputField type='text' name='second-name' rules={[*/}
      {/*        { length: { max: 12 } },*/}
      {/*]}/>*/}
      {/*<InputField type='password' name='password' rules={[*/}
      {/*    'required',*/}
      {/*    'password'*/}
      {/*]}/>*/}
      {/*<InputField type='password' name='confirm-password' rules={[*/}
      {/*    'required',*/}
      {/*    {*/}
      {/*        equal: 'password'*/}
      {/*    }*/}
      {/*]}/>*/}
      <Button className={classes.button} type="submit" variant="contained"
              color="primary">
        Submit
      </Button>
    </InputForm>
  );
};

export default SignUpForm;