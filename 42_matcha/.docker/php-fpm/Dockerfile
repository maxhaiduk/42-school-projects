FROM php:7.4-fpm

RUN apt-get update --fix-missing \
    && apt-get upgrade -y

ADD bin /usr/local/bin/

# common
RUN apt-get install -y unzip curl

# xdebug
RUN pecl install xdebug-2.9.0 && docker-php-ext-enable xdebug
COPY config/xdebug.ini "$PHP_INI_DIR"/conf.d/

# composer
RUN /usr/local/bin/composer-installer.sh\
    && mv composer.phar /usr/local/bin/composer\
    && chmod +x /usr/local/bin/composer\
    && composer --version

# git
RUN apt-get install -y git

# postgreSql php pdo extension
RUN apt-get install -y libpq-dev && \
    docker-php-ext-configure pgsql -with-pgsql=/usr/local/pgsql && \
    docker-php-ext-install pdo pdo_pgsql

ARG USER_UID=33
ARG USER_GID=33

# working directory ownership
RUN chown -R www-data:www-data /var/www

# sync www-data uid/gid with host user
RUN /usr/local/bin/change-user-id.sh www-data "$USER_UID" "$USER_GID"

# composer settings
RUN install -o www-data -g www-data -d /var/www/.composer
ENV PATH="$PATH":/var/www/html/vendor/bin
