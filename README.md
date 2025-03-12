Дипломная работа
создание стенда на базе Распбери для тестирования платы управления
основные файлы github.com/pitrony/diplom
программа на си в папке github.com/pitrony/diplom/orange_test_stend_c
графическая оболочка подготовлена на пайтоне в github.com/pitrony/py_stend_test
при работе в линукс загружено paho-mqtt, smbus, i2c, node-red, influxdb
тестируемая плата подключена к распбери(на тесте орандж z2) через i2c интерфейс, читаются состояния управляющих устройств и передается по mqtt в nodered, анализируется-декодируется входные данные сохраняются в influxdb 
развертывание с помощью docker использовался вариант https://github.com/emield12/docker-influxdb-grafana-nodered-mqtt.git

видео работы прототипа станции https://disk.yandex.ru/i/EjKzI8LhTOwauA
начата разработка программы в среде кютикреатор https://github.com/pitrony/test_board_qtcr.git на с++ 
