import React from 'react';
import SignInForm from '~/components/sign-in-form';
import {Link as RouterLink} from 'react-router-dom';
import makeStyles from "@material-ui/core/styles/makeStyles";
import Link from '@material-ui/core/Link';
import { Container } from "@material-ui/core";
import Button from "@material-ui/core/Button";

const useStyles = makeStyles(() => ({
  linksContainer: {
    marginTop: 20,
    display: 'flex',
    justifyContent: 'space-between',
  },
}));


const SignInPage = () => {

  const classes = useStyles();

  return (
    <Container className={classes.root} maxWidth={'sm'}>
      <SignInForm/>
      <div className={classes.linksContainer}>
        <Link component="button" variant="body2" color="primary">
          <RouterLink to={'/'}>
            Forgot the password?
          </RouterLink>
        </Link>

        <Button variant="outlined" color="secondary">
          <RouterLink to={'/sign-up'}>
            Create an account
          </RouterLink>
        </Button>
      </div>
    </Container>
  )
};

export default SignInPage;
