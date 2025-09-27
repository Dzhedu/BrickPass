# Библиотека BrickPass  
  
**Используется для шифрования парольной информаций.**  
  
# Инструкция  

**Установка**  
  
  
**Шифрование**  
  
```
#include "BrickPass.h"
#include <iostream>

int main() {
    BrickPass bp;
    BrickPass::Result result = bp.Encrypt(5547, 3, "Dzhedu");
    std::cout << "Success: " << result.success << std::endl;
    std::cout << "Message: " << result.message << std::endl;
	return 0;
}
```

Выход:  

```
Success: 1
Message: lizI4l
```

**Дешифрование**  
