import AbstractValidator from './abstract-validator';
import { StringHelper } from '~/helpers';

export default class EqualValidator extends AbstractValidator {

    /**
     * @inheritDoc
     */
    validate(value, payload) {
        let equalToValue = (this.inputFieldsState[payload] || {}).value;

        if (equalToValue === undefined) {
            throw new Error(`Field ${payload} doesn't exists`);
        }

        let valid = value === equalToValue;

        return {
            valid,
            ...(!valid && { message: this.getMessage(payload) })
        }
    }

    getMessage(payload) {

        let inputName = StringHelper.toHumanCaseCap(this.inputName);
        payload= StringHelper.toHumanCaseCap(payload);

        return 'Field {name} must be equal to {equalTo}'
            .replace('{name}', inputName)
            .replace('{equalTo}', payload);
    }
}