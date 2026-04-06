import RequiredValidator from './required-validator';
import LengthValidator from './length-validator';
import EqualValidator from './equal-validator';
import PasswordValidator from './password-validator';
import EmailValidator from './email-validator';

const validators = {
    RequiredValidator,
    LengthValidator,
    EqualValidator,
    PasswordValidator,
    EmailValidator,
};

const getDynamicValidator = (validatorName) => {

    const validator = validators[validatorName];

    if (!validator) {
        throw new Error(`${validatorName} doesn't exists`);
    }

    return validator;
};

export default getDynamicValidator;