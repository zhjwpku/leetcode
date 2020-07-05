# leetcode solutions project framework

## Vagrant

You should installed [virtualbox](https://www.virtualbox.org/) and [vagrant](https://www.vagrantup.com/) on your host machine.

```
## The following command should run on your host machine.
git clone https://github.com/zhjwpku/leetcode.git
cd leetcode
git submodule update --init --recursive
vagrant up
vagrant ssh
```

## HOW TO RUN

```
## The following command should run in the VM after the vagrant ssh
cd leetcode && mkdir -p build && cd build
cmake .. && make
ctest
```

