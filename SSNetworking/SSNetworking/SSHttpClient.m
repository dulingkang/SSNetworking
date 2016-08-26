//
//  SSHttpClient.m
//  SSNetworking
//
//  Created by ShawnDu on 16/8/26.
//  Copyright © 2016年 ShawnDu. All rights reserved.
//

#import "SSHttpClient.h"
#import "AFNetworking.h"

@interface SSHttpClient()
@property (nonatomic, strong) AFHTTPSessionManager *httpSessionManager;
@end

@implementation SSHttpClient

+ (SSHttpClient *)sharedInstance {
    static id sharedInstance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] initSingleton];
    });
    return sharedInstance;
}

- (id)initSingleton{
    if(self = [super init]){
        self.httpSessionManager = [AFHTTPSessionManager manager];
        self.httpSessionManager.requestSerializer = [AFHTTPRequestSerializer serializer];
        self.httpSessionManager.responseSerializer = [AFJSONResponseSerializer serializer];
    }
    return self;
}

- (NSURLSessionDataTask *)post:(NSString *)urlStr
                    parameters:(NSDictionary *)parameters
                       success:(ResultSuccessHandler)succesHandler
                       failure:(ResultFailureHandler)failureHandler {
    
    return nil;
}



@end
