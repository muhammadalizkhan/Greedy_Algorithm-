//You need to use some Function Values, like x = 3, 4, 5
#import <Foundation/Foundation.h>

NSArray* greedyCoinChange(NSArray* availableCoins, NSInteger targetAmount) {
    NSMutableArray* result = [NSMutableArray array];
    NSInteger remainingAmount = targetAmount;
    
    // Sort coins in descending order
    NSArray* sortedCoins = [availableCoins sortedArrayUsingComparator:^NSComparisonResult(id a, id b) {
        return [b integerValue] - [a integerValue];
    }];
    
    for (NSNumber* coin in sortedCoins) {
        NSInteger coinValue = [coin integerValue];
        while (remainingAmount >= coinValue) {
            [result addObject:coin];
            remainingAmount -= coinValue;
        }
    }
    
    if (remainingAmount == 0) {
        return result;
    } else {
        NSLog(@"Cannot make exact change.");
        return nil;
    }
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSArray* availableCoins = @[@25, @10, @5, @1]; // Available coin denominations
        NSInteger targetAmount = 63; // Target amount to make change for
        
        NSArray* change = greedyCoinChange(availableCoins, targetAmount);
        if (change) {
            NSLog(@"Greedy coin change: %@", change);
        }
    }
    return 0;
}
