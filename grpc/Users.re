// TODO: how we can generate this?

module UsersService = {
  module Client = {
    let createUser =
      Lib.Client.request(
        "/proto.UsersService/CreateUser",
        Proto.Users.Proto.UsersService.createUser,
      );
    let readUser =
      Lib.Client.request(
        "/proto.UsersService/ReadUser",
        Proto.Users.Proto.UsersService.readUser,
      );
  };

  module Server = {
    let createUser =
      Lib.Server.route(
        // route should be /packageName.serviceName/rpcName
        "/proto.UsersService/CreateUser",
        Proto.Users.Proto.UsersService.createUser,
      );
    let readUser =
      Lib.Server.route(
        "/proto.UsersService/ReadUser",
        Proto.Users.Proto.UsersService.readUser,
      );
  };
};
