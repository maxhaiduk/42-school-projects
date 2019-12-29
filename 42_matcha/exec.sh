#!/usr/bin/env bash

# it is wrapper around docker-compose with some pre-defined handy shortcuts
# it allows you to interact with application and it's moving parts and provides means
# for getting you env ready and configured, and allows to interact with env after that

# always fail early
set -e

# Disable pseudo-TTY allocation for CI
TTY=""

# docker-compose shorthand
COMPOSE="docker-compose"

# docker service name where commands will be executed
CONTAINER="php-fpm"

USER="www-data"

# execute command in running container
# globals:
#   $COMPOSE, $TTY
# arguments:
#   $1   - in which container to execute command
#   $2.. - command itself
function stack_exec () {
    local CONTAINER=$1; shift
    (set -x; $COMPOSE exec $TTY --user $USER $CONTAINER $@)
}

# spin up ephemeral container and run command in it
# container is removed after command is executed
# entrypoint of container is replaced with bash
# globals:
#   $COMPOSE, $TTY
# arguments:
#   $1   - in which container to execute command
#   $2.. - command itself
function stack_run () {
    local CONTAINER=$1; shift
    (set -x; $COMPOSE run $TTY --rm --user $USER --entrypoint="/bin/bash -c" $CONTAINER "$*")
}

function usage () {
    echo "$(basename "$0") help"
    echo "  display this help message"

    echo "$(basename "$0") [ci] setup"
    echo "  will install all voice's php and npm dependencies"
    echo "  also, will build assets and migrate database"

    echo "$(basename "$0") [ci] composer <arguments>"
    echo "  shortcut for composer in voice container"

    echo "$(basename "$0") [ci] artisan <arguments>"
    echo "  shortcut for artisan in voice container"

    exit -1
}

if [ "$#" -le 0 ]; then
    usage
fi

# capture 1st arg which denotes command
COMMAND=$1; shift 1

# main switch where we detect which top-level command or modifier is passed
case $COMMAND in
    help)
        usage
        ;;

    *)
        # fallback
        echo ">>Running in DEV<<"
        ;;
esac

# shorthand processing switch
case $COMMAND in
    setup)
        stack_run $CONTAINER composer install --prefer-dist
        stack_run $CONTAINER artisan migrate
        ;;

    composer)
        stack_run $CONTAINER composer $@ ;;

    artisan)
        stack_run $CONTAINER php artisan $@ ;;

    bash)
        stack_exec $CONTAINER bash ;;

esac
