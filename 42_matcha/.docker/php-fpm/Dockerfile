FROM php:7.4-fpm

RUN apt-get update --fix-missing \
    && apt-get upgrade -y

# common
RUN apt-get install -y unzip curl

# xdebug
RUN pecl install xdebug-2.9.0 && docker-php-ext-enable xdebug
COPY config/xdebug.ini $PHP_INI_DIR/conf.d/

# composer
COPY composer-installer.sh /usr/local/bin/
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
