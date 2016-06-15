# getpgid
Small Linux executable around the getpgid(2) system call to get Process Group ID

It can be used e.g. to kill a whole process tree spawned from and including the script itself by calling
```bash
sedsid kill -9 -$(getpgid)
```
from inside the script. There is no more need to remember all child PIDs to kill them separately.

# Dependencies
This is solely dependent on `glibc>=2.12`

# Building
```bash
git clone https://github.com/wilriker/getpgid.git
cd getpgid
make
make install
```
It will be installed to
```
/usr/bin/getpgid
```
You can use
```
make PREFIX=/path/to/dir install
```
to customize the installation location.

# Usage
Either use
```
getpgid
```
without any parameters. This will return the PGID of g`getpgid`. This basically only makes sense when called from inside a script.
It is also possible to provide a PID
```
getpgid <PID>
```
that will return the PGID for a valid PID.

# Return codes and output
`getpgid` will return
* 0: Success together with PGID on `stdout`
* 1: PID was provided but not a valid number together with an error message on `stderr`
* 2: PGID could not be determinded due to e.g. invalid PID or missing permissions together with error message on `stderr`
