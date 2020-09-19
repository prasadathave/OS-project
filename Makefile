all: build

build: binaries
  @echo "Building"
  gcc shell.c -o shell

binaries:
  @echo "Building ls..."
  gcc ls.c -o ls

clean:
  @echo "Cleaning"
  rm ls
  rm shell

As such no need of cleaning stuff. We just need to do gcc shell.c and program can run
