import React from 'react';
import InputForm, { InputField } from '~/components/input-form';
import { Button, makeStyles } from "@material-ui/core";

const useStyles = makeStyles((theme) => ({
  form: {
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
    width: 200,
    [theme.breakpoints.down('xs')]: {
      width: '100%',
    },
  }
}));

const SignInForm = () => {

  const classes = useStyles();

  return (
    <InputForm className={classes.form} id='sign-in-form'>
      <InputField className={classes.textField} type='text' name='login'
                  label='Login'/>
      <InputField className={classes.textField} type='password' name='password'
                  label='Password'/>
      <Button className={classes.button} type="submit" variant="contained"
              color="primary">
        Submit
      </Button>
    </InputForm>
  );
};

export default SignInForm;
