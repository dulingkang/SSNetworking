//
//  SSHttpClient.h
//  SSNetworking
//
//  Created by ShawnDu on 16/8/26.
//  Copyright © 2016年 ShawnDu. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^ResultSuccessHandler)(id responseObject);
typedef void (^ResultFailureHandler)(NSError *error);

@interface SSHttpClient : NSObject

/**
 The URL used to construct requests full url.
 */
@property (readonly, nonatomic, strong) NSURL *baseURL;

/**
 If need configure custom header, and the header value is consistent any time, should set this instance before any request, such as in `application:application:launchOptions` this method.
 If your header value is varied, and don't have any consistent header value, please don't set this instance, instead, need to set instance `realtimeHeader`.
 
 key, value in basicHeader will be configured in http header:
 `[self.httpSessionManager.requestSerializer setValue:value forHTTPHeaderField:key]`. Only set once.
 */
@property (nonatomic, strong) NSMutableDictionary *basicHeader;

/**
 If need configure custom header, and the header value is varied every request, need to set this instance.
 
 key, value in basicHeader will be configured in http header:
 `[self.httpSessionManager.requestSerializer setValue:value forHTTPHeaderField:key]`. set in every request.
 */
@property (nonatomic, strong) NSMutableDictionary *realtimeHeader;

/**
 Singleton method, in this method, instance httpSessionManager which class is AFHTTPSessionManager also init.
*/
+ (SSHttpClient *)sharedInstance;

/**
 Creates and runs an `NSURLSessionDataTask` with a `POST` request.
 @param urlStr The URL string used to create the request URL.(`baseURL`+`urlStr`)
 @param parameters The parameters to be encoded according to the client request serializer.
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes one arguments: the response object created by the client response serializer.
 @param failure A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes one arguments: the error describing the network or parsing error that occurred.
*/
- (NSURLSessionDataTask *)post:(NSString *)urlStr
                    parameters:(NSDictionary *)parameters
                       success:(ResultSuccessHandler)succesHandler
                       failure:(ResultFailureHandler)failureHandler;
@end
