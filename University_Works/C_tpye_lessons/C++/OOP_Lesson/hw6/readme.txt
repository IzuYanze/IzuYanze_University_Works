1. 姓名
>>  [NULL]

2. 學號
>>  [NULL]

3. e-mail
>>  [NULL]

4. 測試環境(哪一台工作站):
>>  FreeBSD

5. 完成的作業項目 (一一列出，並說明如何操作)
    (I) Customer.h、Customer.cpp (60%)：
        Customer.h:
            於Customer, OrdinaryCustomer, PremiumCustomer 三個class內分別加上所需要的private or protected data member。
            作業pdf中有六個 (virtual) ，請同學自行判斷何處該保留virtual，若不需要則刪除。
        Customer.cpp:
            僅能實作Customer.h中現有的public member functions。
>>      我嫌st nd rd th的回傳太麻煩就直接做一個member functions了 希望不會有影響
        <Copy Constructor要求>
            假設有第一個OrdinaryCustomer物件A("Vivian", "Wang", "Taichung", "...")，且還沒有任何PremiumCustomer
            此時若呼叫copy constructor以利用A來創建第二個OrdinaryCustomer物件B
            則Copy Constructor應印出:
            "Calling the copy constructor to copy data from: Vivian Wang, at Taichung."
            "This is the 2nd OrdinaryCustomer, and 2nd Customer."
        評分方式：
            通過main1 (即作業pdf中main的標準答案版) +25 
>>          (v)
            通過main2 (進階版) +25 
>>          (v)
            通過main3 (隱藏版) +10 
>>          (x) 我不知道
    (II) main.cpp (30%)
        完成以下兩部分，並且需做到dynamic binding
            Produce outputs
            Release previously allocated memory
>>          (v) 應該有吧?


6. Bouns內容(助教會依Bonus內容酌量給分)
>>  
7. Reference
>>  https://cplusplus.com/reference/string/string/
    https://text-compare.com/
    https://stackoverflow.com/questions/30551904/how-to-initialize-an-array-in-the-member-initializer-list
    http://140.123.101.97/forum/viewtopic.php?t=7759
    http://140.123.101.97/forum/viewtopic.php?t=7757
8. 其他想補充告知助教的事項也可以在此說明
>>  助教辛苦ㄌ