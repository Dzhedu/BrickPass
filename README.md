# Библиотека BrickPass  
  
**Может быть использовано для шифрования парольной информаций.**  
  
# Инструкция по API  
  
**Запрос версии**  
  
```
#include "BrickPass.h"
#include <iostream>

int main() {
    BrickPass bp;
	std::cout << "BrickPass version: " << BrickPass::GetVersion() << std::endl;
	return 0;
}
```

Вывод:  

```
BrickPass version: 1.0.0
```

**Пример шифрования**  

```
#include "BrickPass.h"
#include <iostream>

int main() {
    BrickPass bp;
	BrickPass::Result result = bp.Encrypt(123, 45, "HelloWorld");
	std::cout << "Encryp Result: " << (result.success) << std::endl;
	std::cout << "Message: " << result.message << std::endl;
	return 0;
}
```

Вывод:  

```
Encryp Result: 1
Message: ZptoeIgomq
```

**Пример дешифрования**  

```
#include "BrickPass.h"
#include <iostream>

int main() {
    BrickPass bp;
	BrickPass::Result result = bp.Decrypt(123, 45, "ZptoeIgomq");
	std::cout << "Decrypt Result: " << (result.success) << std::endl;
	std::cout << "Message: " << result.message << std::endl;
	return 0;
}
```

Вывод:  

```
Decrypt Result: 1
Message: HelloWorld
```

# Область применения  

**Для скриптов, встроенная в код парольная информация может быть зашифрована с помощью BrickPass.  
Для шифрования парольной информации в таблицах БД, в том числе ключи ssh. Таким образом, присутствие 
в файловой системе открытых паролей может быть исключено, что может уберечь от раскрытия даже при получении доступа к ФС ОС.
  
Буду благодарен форкам, применением в других языках. 
Буду рад конструктивной критике.**
