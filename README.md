### Running on Docker

Build:
```sh
    $ docker build . --no-cache
```

or

```sh
    $ docker build .
```

Start docker with your container tag:
```sh
    $ docker run -it -v "$PWD":/home/dummy --env-file env 8de1ffb65323 zsh
```

Go to mount entry  "/home/dummy"

```sh
    $ cd /home/dummy
```

Run examples
```sh
    $ make all
```

Obs 
a) change the container tag <876b00058d0f> with your created tag (Successfully built XXXXXXXXXXXX)
b) $PWD is a linux commant to get the current directory, if you are not familiar with docker mount volues please follow [this link](https://docs.docker.com/storage/volumes/).