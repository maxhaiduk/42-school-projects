import AbstractValidator from './abstract-validator';
import { StringHelper } from '~/helpers';

export default class RegexpValidator extends AbstractValidator {

    patterns = {
        '[a-z]': '{name} must contain at least one lowercase character',
        '[A-Z]': '{name} must contain at least one capital character',
        '[0-9]': '{name} must contain at least one number',
    };

    /**
     * @inheritDoc
     */
    validate(value, payload) {

        let valid = false;
        let pattern;
        let patterns = this.getPatterns();

        for (pattern in patterns) {
            if (!patterns.hasOwnProperty(pattern)) {
                continue;
            }

            let regexp = new RegExp(pattern);

            valid = regexp.test(value);

            if (!valid) {
                break;
            }
        }

        return {
            valid,
            ...(!valid && { message: this.getMessage({
                    description: this.patterns[pattern]
                })
            })
        }
    }

    /**
     * @inheritDoc
     */
    getMessage({ description }) {

        return description.replace(
            '{name}',
            StringHelper.toHumanCaseCap(this.inputName)
        )
    }

    fetchPatterns(patterns) {

        return patterns.map(pattern => {
            if (pattern in this.patterns) {
                return {[pattern]: this.patterns[pattern]}
            }
            throw new Error(`${pattern} is wrong pattern`);
        }).reduce((set, pattern) => Object.assign(set, pattern), {});
    }
}