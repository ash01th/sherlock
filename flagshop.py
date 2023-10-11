flag=1
coins=50
f1_price=20
f2_price=10
f3_price=200
f1_quantity=2
f2_quantity=2
f3_quantity=1
def buy(coins):
    print("choose a product")
    print("press 1 to buy item 1")
    print("press 2 to buy item 2")
    print("press 3 to buy item 3")
    var=int(input("enter your choice"))
    qty=int(input("enter quantity to purchase"))
    if var==1 and qty<=f1_quantity and coins>=f1_price:
        coins=coins-(qty*f1_price)
        print("sh3rl0ck{D33r}")
    elif var==2 and qty<=f2_quantity and coins>=f2_price:
        coins=coins-(qty*f2_price)
        print("_st@lk3r")
    elif var==3 and qty<=f3_quantity and coins>=f3_price:
        coins=coins-(qty*f3_price)
        print("D3t3ctiv3}")
    else:
        print("invalid input try again")
    return coins
while(flag):
    print("----------------------------------------------------------------")
    print("--------------------welcome to flag store-----------------------")
    print("----------------------------------------------------------------")
    print(f"you have {coins} coins")
    print("available items:")
    print(f"part 1/3 of flag : price={f1_price} quantity={f1_quantity}")
    print(f"part 2/3 of flag: price={f2_price} quantity={f2_quantity}")
    print(f"part 3/3 of flag : price={f3_price} quantity={f3_quantity}")
    coins=buy(coins)
    flag=int(input("press 0 to exit press 1 to continue "))
    
