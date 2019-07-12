import AbstractValidator from './abstract-validator';
import { StringHelper } from '../../../../../helpers';


export default class RequiredValidator extends AbstractValidator {

    /**
     * @inheritDoc
     */
    validate(value, payload) {
        const valid = (value !== undefined && value.length !== 0);

        return {
            valid,
            ...(!valid && { errorMessage: this.getErrorMessage(payload) })
        }
    }

    /**
     * @inheritDoc
     */
    getErrorMessage(payload) {
        // const rawMessage = 'Field {name} is required';

        return 'Field {name} is required'
            .replace('{name}', StringHelper.ucFirst(this.inputName));
    }
}