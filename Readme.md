## Exam Rank 5 simple test
(obviously, replace '_xx' with '_00', '_01' or '_02')
main_*.cpp files are included in subfolder ```bash attachments ```


### compile it...

```bash
c++ -Wextra -Werror -Wall ./cpp_module_xx/*.cpp -o wl
```

### run it...
```bash
./wl | cat -e > ./cpp_module_xx/o.txt
```

### check it...
``` bash
diff ./cpp_module_xx/s.txt ./cpp_module_xx/o.txt
```
