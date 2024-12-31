#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

class FinanceManager {
private:
    std::vector<double> priceChanges; // 存储所有价格变动
    double totalProfit;               // 总利润
    std::string fileName;             // 文件名

    void loadFromFile();              // 从文件加载数据
    void saveToFile();                // 保存数据到文件

public:
    FinanceManager(const std::string& file); // 构造函数
    ~FinanceManager();                       // 析构函数

    void recordPriceChange(double change);   // 记录价格变动
    double getTotalProfit() const;           // 获取总利润
    void printTransactions(int count = -1) const; // 打印交易记录
    void printTotalProfit() const;           // 打印总利润
};

extern FinanceManager financeMgr; // 声明全局对象

#endif // FINANCE_H