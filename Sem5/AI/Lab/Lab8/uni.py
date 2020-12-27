preds_x = 0
arg_y = [None for i in range(10)]

pred_arr = [None for i in range(10)]
arg_arr = [[None for i in range(10)] for i in range(10)]


def merge():
    flag = 0
    for i in range(preds_x-1):
        for j in range(arg_y[i]):
            if(arg_arr[i][j] != arg_arr[i+1][j]):
                if(flag == 0):
                    print("subs :")
                    print(arg_arr[i+1][j], "/", arg_arr[i][j])
                    flag += 1

        if(flag == 0):
            print("Arrays are same!!!! no subs needed!!!")
            

def check_cond():
    pred_flag = 0
    arg_flag = 0
    for i in range(preds_x-1):
        if(pred_arr[i] != pred_arr[i+1]):
            print("preds not same ")
            pred_flag = 1
            break
    if(pred_flag != 1):
        ind = 0
        key = arg_y[ind]
        l = len(arg_y)
        for i in range(0, key-1):
            if i >= key:
                continue
            if ind != l-1:
                ind += 1
                key = arg_y[ind]
            if(arg_y[i] != arg_y[i+1]):

                print("arg_arrs Not Same..!")
                arg_flag = 1
                break

        if(arg_flag == 0 and pred_flag != 1):
            merge()

def output():
    print("Preds are: ")
    for i in range(preds_x):
        print(pred_arr[i], "(", end="")
        for j in range(arg_y[i]):
            print(arg_arr[i][j], end="")
            if(j != arg_y[i]-1):
                print(",", end="")
        print(")")

def main():
    global preds_x
    ch = 'y'
    while(ch == 'y'):
        preds_x = int(input("No. of preds:"))
        for i in range(preds_x):
            print("Enter pred ", (i+1), " :")
            pred_arr[i] = input()
            print("No. of args for pred ", pred_arr[i], " :")
            arg_y[i] = int(input())

            for j in range(arg_y[i]):
                print("Enter arg ", j+1, " :")
                arg_arr[i][j] = input()
        output()
        check_cond()
        ch = input("Continue ??? (y/n) :")
main()