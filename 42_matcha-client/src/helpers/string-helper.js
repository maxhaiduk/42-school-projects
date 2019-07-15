export default class StringHelper {

    /**
     * Capitalises first character of the string
     *
     * @param {string} string
     * @return {string}
     */
    static ucFirst(string) {
        return string.charAt(0).toUpperCase() + string.slice(1);
    }

    /**
     * Capitalises first character of each word in the string
     *
     * @param string
     * @return {string}
     *
     * 'foo bar' => 'Foo Bar'
     * 'fOO bAr' => 'FOO BAr'
     */
    static capitalize(string) {
        return string.split(' ')
            .map((word) => this.ucFirst(word))
            .join(' ');
    }

    /**
     * Converts string to humanCase
     *
     * @param string
     * @return {string}
     *
     * 'camelCase' => 'camel Case'
     * 'kebab-case' => 'kebab case'
     * 'snake_case' => 'snake case'
     */
    static toHumanCase(string) {
        return string.replace(this._getCommonPattern(), ' ');
    }

    /**
     * Converts string to humanCase and capitalizes each word
     * @see toHumanCase
     *
     * @param string
     * @return {string}
     *
     * 'kebab-case' => 'Kebab Case'
     */
    static toHumanCaseCap(string) {
        return this.capitalize(this.toHumanCase(string));
    }

    static _getCommonPattern() {
        return /(?<=[a-z])(?=[A-Z])|_| |-/;
    }
}