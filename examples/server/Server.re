open Lwt.Infix;

module UsersProto = Proto.Users.Proto;

let server = () => {
  let read_user =
    Grpc.Users.UsersService.Server.readUser(request => {
      open UsersProto.ReadUserResponse;
      open UsersProto.User;

      let id = request.id;
      let user = {
        id,
        first_name: "Tomasz",
        last_name: "Cichocinski",
        date_of_birth: 0,
      };
      Lwt.return({user: Some(user)});
    });

  Lib.Server.listen(~port=50051, [read_user]);
};

Lwt.async(() => server());
{
  let (forever, _) = Lwt.wait();
  Lwt_main.run(forever);
};
