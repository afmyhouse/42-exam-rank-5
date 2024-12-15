## Exam Rank 5 simple test
(obviously, replace '_xx' with '_00', '_01' or '_02')

There are some ```main**.cpp``` files ready, and their outputs ```s.txt```, included in subfolder ``` attachments/ ```. Copy it to cpp_module_xx folder and on the the root folder ...


### compile it...

```bash
c++ -Wextra -Werror -Wall ./cpp_module_xx/* -o wl
```

### run it...
```bash
./wl | cat -e > ./cpp_module_xx/o.txt
```

### check it...
``` bash
diff ./cpp_module_xx/s.txt ./cpp_module_xx/o.txt
```
