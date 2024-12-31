
#ifndef TOKEN_H
#define TOKEN_H
#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

class Token {
public:
    // 解析命令和参数
    static std::vector<std::string> parseCommand(const std::string& input);

    static bool isValidCommand(const std::string& command);

    // 验证用户ID是否合法
    static bool isValidUserID(const std::string& userID);

    // 验证密码是否合法
    static bool isValidPassword(const std::string& password);

    // 验证用户名是否合法
    static bool isValidUsername(const std::string& username);

    // 验证权限是否合法
    static bool isValidPrivilege(const std::string& privilege);

    // 验证ISBN是否合法
    static bool isValidISBN(const std::string& isbn);

    // 验证书名是否合法
    static bool isValidBookName(const std::string& bookName);

    // 验证作者是否合法
    static bool isValidAuthor(const std::string& author);

    // 验证关键词是否合法
    static bool isValidKeyword(const std::string& keyword);

    // 验证价格是否合法
    static bool isValidPrice(const std::string& price);

    // 验证数量是否合法
    static bool isValidQuantity(const std::string& quantity);

    // 验证总成本是否合法
    static bool isValidTotalCost(const std::string& totalCost);
};

#endif // INPUT_HANDLER_H
#endif //TOKEN_H
