import AbstractValidator from './abstract-validator';
import { StringHelper } from '~/helpers';

export default class RequiredValidator extends AbstractValidator {

    /**
     * @inheritDoc
     */
    validate(value, payload) {
        const valid = Boolean(value);

        return {
            valid,
            ...(!valid && { message: this.getMessage(payload) })
        }
    }

    /**
     * @inheritDoc
     */
    getMessage(payload) {

        let inputName = StringHelper.toHumanCaseCap(this.inputName);

        return 'Field {name} is required'
            .replace('{name}', inputName);
    }
}