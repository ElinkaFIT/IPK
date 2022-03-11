# IPK projekt 1

Server komunikující prostřednictvím HTTP protokolu.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Usage

Po stažení souborů do vašeho počítače použijte následující příkazy v terminálu. 
Namísto '12345' můžete zadat vlastní číslo portu. 

```
$ make
$ ./hinfosvc 12345 &
```

## Získání doménového jména

```
$ GET http://servername:12345/hostname
```
nebo
```
$ curl http://servername:12345/hostname
```

## Získání informací o CPU

```
$ GET http://servername:12345/cpu-name
```
nebo
```
$ curl http://servername:12345/cpu-name
```

## Aktuální zátěž

```
$ GET http://servername:12345/load
```
nebo
```
$ curl http://servername:12345/load
```

## Deployment

Additional notes on how to deploy this on a live or release system. Explaining the most important branches, what pipelines they trigger and how to update the database (if anything special).

### Server

* Live:
* Release:
* Development:

### Branches

* Master:
* Feature:
* Bugfix:
* etc...

## Additional Documentation and Acknowledgments

* Project folder on server:
* Confluence link:
* Asana board:
* etc...
