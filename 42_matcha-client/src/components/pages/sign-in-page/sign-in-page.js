import React from 'react';
import SignInForm from '~/components/sign-in-form';
import {Link as RouterLink} from 'react-router-dom';
import makeStyles from "@material-ui/core/styles/makeStyles";
import Link from '@material-ui/core/Link';
import { Container } from "@material-ui/core";
import Button from "@material-ui/core/Button";
import Grid from "@material-ui/core/Grid";

const useStyles = makeStyles(() => ({
    linksContainer: {
      marginTop: 20,
    },
    button: {
      width: '100%'
    }
}));


const SignInPage = () => {

  const classes = useStyles();

  return (
    <Container maxWidth={'sm'}>
      <SignInForm/>
        <Grid justify="center" className={classes.linksContainer} container spacing={4}>
          <Grid item xs={12} sm={6}>
            <Button className={classes.button} color="secondary">
              <Link component={RouterLink} variant="body2" color="primary" to={'/'}>
                Forgot the password?
              </Link>
            </Button>
          </Grid>

          <Grid item xs={12} sm={6}>
            <Button className={classes.button} variant="outlined" color="secondary">
              <Link component={RouterLink} to={'/sign-up'}>
                Create an account
              </Link>
            </Button>
          </Grid>
        </Grid>
    </Container>
  )
};

export default SignInPage;
