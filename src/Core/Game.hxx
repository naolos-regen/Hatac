#ifndef HATAC_GAME
# define HATAC_GAME

namespace Hatac
{
	class Game
	{
		private:
			int argc;
			char ** argv;
		public:
			Game(int argc, char ** argv) 
				: argc(argc)
				, argv(argv)
			{};

			void options();
	};
};

#endif
